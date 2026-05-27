import express from 'express';
import { router } from './api.js';
import cors, { type CorsOptions } from "cors";

const app = express();
const port = 3000;

const options: CorsOptions = {
    origin: "http://localhost:5173",
};

// static files
app.use(express.static("public"));

// middleware
app.use(express.json());
app.use(cors(options));
app.use(express.urlencoded({ extended: true }));

app.use("/", router);

app.listen(
    port, 
    () => console.log(`App running on port ${port}`)
);