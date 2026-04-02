import type { iCocktailCollections, iCocktail } from './types';


const template: HTMLTemplateElement = document.querySelector("#cocktailTemplate")!;
const main = document.querySelector("main")!;


async function loadCocktail(ingredient: string) {
  const result = await fetch(`https://www.thecocktaildb.com/api/json/v1/1/search.php?s=${ingredient}`);
  const data: iCocktailCollections = await result.json();

  return data;
}

function createCocktailCard(data: iCocktail) {
  const clone = document.importNode(template.content, true);
  const cocktailTitle = clone.querySelector(".cocktailName")!;

  cocktailTitle.insertAdjacentText("beforeend", data.strDrink);

  const cocktailInstructions = clone.querySelector(".cocktailInstructions")!;
  cocktailInstructions.insertAdjacentText("beforeend", data.strInstructions);

  const cocktailImage: HTMLImageElement = clone.querySelector(".cocktailImage")!;
  cocktailImage.src = data.strDrinkThumb;

  return clone;
}
function showCocktailCard(drinks: iCocktail[]) {
  main.replaceChildren();

  drinks
    .map(drink => createCocktailCard(drink))
    .forEach(c => main.appendChild(c));
}

export async function loadCocktailsOfIngredient(ingredient: string) {
  const collection = await loadCocktail(ingredient);
  showCocktailCard(collection.drinks);
}
