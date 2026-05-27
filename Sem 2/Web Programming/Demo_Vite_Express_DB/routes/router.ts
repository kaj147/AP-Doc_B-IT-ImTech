import express from "express";
import { iAnimals } from "../types.js";
import { createAnimal, getAnimals } from "../database/queries";

export const router = express.Router();

router.get(
    "/animals/list",
    async (req, res) => {
        const animals : iAnimals[] = await getAnimals();
        res.status(200).json(animals);
    }
);

router.post(
    "/animal",
    async (req, res) => {
        const animal : iAnimals = req.body;
        await createAnimal(animal);
        res.status(200).send("Animal added")
    }
);