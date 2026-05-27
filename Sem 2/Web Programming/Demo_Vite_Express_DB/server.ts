import express from 'express';
import { router } from './routes/router.js';

const app = express();
const hostname = "127.0.0.1";
const port = 3000;

app.use(express.json());
app.use(express.urlencoded({extended: true}));

app.use('/', router);

app.use((req, res) => {
    res.status(404).send("API not found");
});

app.listen(
    port,
    hostname,
    () => console.log(`Running on http://${hostname}:${port}`)
)