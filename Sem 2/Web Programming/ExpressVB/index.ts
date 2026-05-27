import  express, { type Request, type Response } from 'express';

const app = express();

const port = 3000;
const hostname = "0.0.0.0";

app.use(express.json());
app.use(
    express.urlencoded(
        {
            extended: true
        }
    )
)
app.use(express.static("public"));

const obj = {
    soort: "Vogels",
    dier: "Pinguin",
    naam: "Freddy",
    eierenGelegd: 0
}

interface iEi {
    "kwaliteit": "ZS" | "S" | "G" | "ZG",
    "aantaldooiers": number,
    "kleur": "wit" | "bruin" | "spikkel"
}

interface iEireren {
    eieren: iEi[];
}

// app.get(
//     "/",
//     (request : Request, response : Response) => {

//         response.type("application/json");
//         response.send(obj);
//     }
// );

app.get(
    "/:soort/:dier/:naam",
    (request : Request, response : Response) => {
        const soortParam = request.params.soort;
        const dierParam = request.params.dier;
        const naamParam = request.params.naam;

        const eierenGelegd = request.query.eierenGelegd;
        const newName = request.query.newName;

        if(newName != null)
            obj.naam = newName.toString();
        
        if(eierenGelegd != null)
            obj.eierenGelegd += parseInt(eierenGelegd.toString());

        response.json(obj);
    }
);

app.post(
    "/eieren",
    ( request, response) => {
        const body : iEireren = request.body;
        const eierenArray = body.eieren;

        response.type("json");
        response.send(obj);
    }
)


app.listen(
    port, 
    hostname,
    () => console.log(`Webserver started @${hostname}:${port}`)
);