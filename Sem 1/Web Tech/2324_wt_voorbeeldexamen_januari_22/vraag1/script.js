const headerH1 = document.querySelector("header h1");
const headerNav = document.querySelector("header nav");

let isOut = false;

headerH1.addEventListener("click", () => {
	// remove both first
	headerNav.classList.remove("in", "out");

	// add correct class
	headerNav.classList.add(isOut ? "in" : "out");

	isOut = !isOut;
});

