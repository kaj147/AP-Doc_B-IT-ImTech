import './style.css'

interface iStudent {
  voornaam: string,
  achternaam: string,
  klas: "IMT" | "SOF" | "IOT" | "AI" | "CSC";
}

const student : iStudent[] = [
  {
    voornaam: "Alin",
    achternaam: "Vermeulen",
    klas: "IMT"
  },
  {
    voornaam: "Joske",
    achternaam: "Palinckx",
    klas: "CSC",
  }
]

const tableBody = document.querySelector("#studentsTable>tbody")!;

const button : HTMLElement = document.querySelector("button")!;


button.addEventListener(
  "click",
  e=> {
  tableBody.classList.toggle("redCell");
}
);

const nodeList = document.querySelectorAll("td");
const arr = [...nodeList];

const studentRows = student.map(s=> `<tr>
  <td>${s.achternaam}</td>
  <td>${s.voornaam}</td>
  <td>${s.klas}</td>
  </tr>`
  ).join("");

  tableBody.insertAdjacentHTML("beforeend", studentRows);
  

