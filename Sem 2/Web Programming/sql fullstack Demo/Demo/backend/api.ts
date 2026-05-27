import express from "express";
import {
  insertKost,
  insertReis,
  selectAlleReizen,
  selectReis,
  selectKosten,
} from "./db.js";

// PRICIPLE:
// GET DATA
// CALL QUERY
// GIVE DATA

const router = express.Router();

router.get("/reizen", (req, res) => {
  const reizen = selectAlleReizen();
  res.json(reizen);
});

router.post("/reis", (req, res) => {
  const bestemming = req.body.bestemming;
  const jaar = req.body.jaar;

  const result = insertReis(bestemming, jaar);

  // WE DONT USE return, BUT res. instead, because thats the result (res) when we make the callback function (req, res) => {}
  res.json(result);
});
router.get("/reis/:id", (req, res) => {
  const id = parseInt(req.params.id);

  const reis = selectReis(id);

  res.json(reis);
});
router.post("/reis/:id/kost", (req, res) => {
  const id = parseInt(req.params.id);
  const uitgave = req.body.uitgave;
  const prijs = req.body.prijs;

  const result = insertKost(id, uitgave, prijs);

  res.json(result);
});
router.get("/reis/:id/kosten", (req, res) => {
  const id = parseInt(req.params.id);

  const kosten = selectKosten(id);

  res.json(kosten);
});
export { router };
