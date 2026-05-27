import './style.css'
import type { iAnimals } from './types.js';

async function fetchAnimals() {
  const response: Response = await fetch("http://localhost:3000/animals/list");
  const animals: iAnimals[] = await response.json();

  let table:HTMLElement = document.querySelector("#animals");

  animals.forEach((animal: iAnimals) => {
    let row:HTMLElement = document.createElement("tr");
    table.appendChild(row);
    row.appendChild(createRowElement(animal.id.toString()));
    row.appendChild(createRowElement(animal.name));
    row.appendChild(createRowElement(animal.species));
    row.appendChild(createRowElement(animal.age.toString()));
    row.appendChild(createRowElement(animal.gender));
  });
}

function createRowElement(value : string) : HTMLElement {
  let td: HTMLElement = document.createElement("td");
  td.innerText = value;
  return td;
}

fetchAnimals();

const form : HTMLFormElement = document.querySelector("#animalform")!;

form.onsubmit = async (event) => {
  event.preventDefault();

  await fetch("http::/localhost:3000/animal", {
    method: "POST"
  })
}