import express from "express";
import { router } from "./api.js";
import cors, { type CorsOptions } from "cors";

// U can memorize this file because its always the same

const app = express();
const port = 3000;

// we implement CORS to connect front- to backend
const corsOptions: CorsOptions = {
  origin: "http://localhost:5173",
  methods: "GET, POST",
};

app.use(cors(corsOptions));

// static files
app.use(express.static("public"));

// init middelware
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.use("/", router); // use router from api.ts, root (localhost:3000/)

app.listen(port, () => console.log(`App running on port ${port}`));
