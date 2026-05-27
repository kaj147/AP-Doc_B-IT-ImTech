import express from 'express';
import { router } from './reiskostenrouter.js';

const app = express();
const port = 3000;

// static files
app.use(express.static("public"));

// init middelware
app.use(express.json());
app.use(express.urlencoded({extended: true}));

app.use("/", router)

app.listen(
    port,
    () => console.log(`App running on port ${port}`)
);