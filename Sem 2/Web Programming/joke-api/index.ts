const urlCatogorie = "https://v2.jokeapi.dev/categories";

async function getCatogories(): Promise<string[]> {
    const response = await fetch(urlCatogorie);
    const data = await response.json();
    return data.categories;
}

async function run() {
    const categories = await getCatogories();

    console.log(categories);

    console.log("Beschikbare catergoriën");
    await categories.forEach((c, i) => {
        console.log(`${i}. ${c}`);
    });
}

run();

// async function getCategories() {
//     const response = await fetch("https://v2.jokeapi.dev/categories");
//     const data = await response.json();
//     console.log(data);
//     const categories = data.categories;

//     console.log("Categories:");
//     categories.forEach((category: string) => {
//         console.log(category);
//     });
// }

// getCategories();