import { loadCocktailsOfIngredient } from './api';
import './style.css'

const ingredientSelector : HTMLFormElement = document.querySelector("#ingredientSelector")!;
ingredientSelector.addEventListener(
  "submit",
  (e: Event) => {
    e.preventDefault();
    
    const formData = new FormData(ingredientSelector);

    const ingredient = formData.get("ingredient")?.toString();

    if(ingredient)
      loadCocktailsOfIngredient(ingredient);
  }
);