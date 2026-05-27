import express from "express";
import type { iReis } from "./types.js";
import { insertKost, insertReis, selectAll, selectReis, selectKosten } from "./db.js";
import { utimes } from "node:fs";

const router = express.Router();

router.get(
    "/reizen",
    (req, res) => {
        const reizen = selectAll();
        res.json(reizen);
    }
);

router.post(
    "/reis",
    (req, res) => {
        const bestemming = req.body.bestemming;
        const jaar = req.body.jaar;

        const result = insertReis(bestemming, jaar);

        if (!result)
            return res.json({result: "failed"});

        res.json({result: "ok"});
    }
);
router.get(
    "/reis/:id",
    (req, res) => {
        const id = parseInt(req.params.id);

        const reis = selectReis(id);

        if (!reis)
            return res.json ({result: `id: ${id} not found`});

        res.json(reis);
    }
);
router.post(
    "/reis/:id/kost",
    (req, res) => {
        const id = parseInt(req.params.id);
        const uitgave = req.body.uitgave;
        const prijs = req.body.prijs;

        const result = insertKost(id, uitgave, prijs);

        if (!result)
            return res.json({result: `id: ${id} not found`})

        res.json({result: "ok"});
    }
);
router.get(
    "/reis/:id/kosten",
    (req, res) => {
        const id = parseInt(req.params.id)

        const kosten = selectKosten(id);

        if (kosten === undefined)
            return res.json({result: `id: ${id} not found`});
        res.json(kosten);
    }
);
export { router };