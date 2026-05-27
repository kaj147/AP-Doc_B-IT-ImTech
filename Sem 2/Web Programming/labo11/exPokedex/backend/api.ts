import { Router } from "express";
import { CatchPokemon, ReleasePokemon, SelectAllPokemon } from "./queries";

const router = Router();

router.get(
    "/pokedex", 
    async (req, res) => {
        const result = await SelectAllPokemon()
        res.json({result});
    }
)

router.post(
    "/pokedex", 
    (req, res) => {
        const id = req.body.id;

        const result = CatchPokemon(id);
        res.json({result});
    }
)

router.delete(
    "/pokedex", 
    (req, res) => {
        const id = req.body.id;

        const result = ReleasePokemon(id);
        res.json({result});
    }
)

router.get(
    "/party", 
    (req, res) => {
        res.json({});
    }
)

export {router}