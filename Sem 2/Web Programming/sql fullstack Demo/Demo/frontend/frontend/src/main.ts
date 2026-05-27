import "./style.css";

const formNewReis: HTMLFormElement = document.querySelector("#nieuweReisForm")!;
formNewReis.addEventListener("submit", async (e) => {
  // Prevent default as usual
  e.preventDefault();

  // Get data from the form using FormData
  const formData = new FormData(formNewReis);
  const bestemming = formData.get("reisBestemminng");
  const jaar = formData.get("reisjaar");

  await fetch("http://localhost:3000/reis", {
    method: "post",
    headers: {
      "content-type": "application/json",
    },
    body: JSON.stringify({ bestemming, jaar }),
  }); // we don't want get but POST, thats why we use the method and headers
});
