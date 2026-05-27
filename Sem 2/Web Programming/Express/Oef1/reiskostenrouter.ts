import express from 'express';
import { type iKost, type iReis } from './types.js';

const router = express.Router();

const reizen: iReis[] = [];

function VindReis(reisId : string) {
    const selectedReis = reizen.filter(r => r.id === reisId)
        if (selectedReis.length == 0)
            return false;

        return selectedReis[0]!
}

router.get(
    "/reizen",
    (req, res) => {
        res.json(reizen);
    }
);

router.post(
    "/reis",
    (req, res) => {
        const reis: iReis = req.body;
        reis.id = (reizen.length + 1).toString();
        reis.kosten = [];

        reizen.push(reis);

        res.json({status: "ok"});
    }
)

router.get(
    "/reis/:id",
    (req, res) => {
        const reisId = req.params.id;

        const result = VindReis(reisId);

        if (result === false)
            res.json({status: `ERROR: reisid ${reisId} not found`});
    }
);

router.post(
    "/reis/:id/kost",
    (req, res) => {
        const reisId = req.params.id;
        const result = VindReis(reisId);
        if (result === false)
            res.json({status: `ERROR: reisid ${reisId} not found`});
        else {
            const kost: iKost = req.body;
            result.kosten.push(kost);
            res.json({status: "ok"});
        }
    }
)

router.get(
    "/reis/:id/kosten",
    (req, res) => {
        const reisId = req.params.id;
        const result = VindReis(reisId);
        if (result === false)
            res.json({status: `ERROR: reisid ${reisId} not found`});
        else {
            res.json({status: "ok"});
        }
    }
)
export { router};