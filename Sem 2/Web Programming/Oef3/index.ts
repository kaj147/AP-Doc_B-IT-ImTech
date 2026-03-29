class Movies {
    title: string = "";
    year: number = 0;
    actors: string[] = [];
    metascore: number = 0;
    seen: boolean = false;
};

const myFavoriteMovie: Movies = {
    title: "The Empire Strikes Back",
    year: 1980,
    actors: [
        "Mark Hamill",
        "Harrison Ford",
        "Carrie Fisher"
    ],
    metascore: 82,
    seen: true,
};

const myWorstMovie: Movies = {
    title: "The Empire Strikes Back",
    year: 1980,
    actors: [
        "Mark Hamill",
        "Harrison Ford",
        "Carrie Fisher"
    ],
    metascore: 82,
    seen: true,
};

function printer(movie : Movies)
{
    console.log(`My worst movie:
    ${movie.title} (${movie.year})
    Actors: ${movie.actors.join(", ")}
    Metascore: ${movie.metascore}
    Seen: ${movie.seen ? "YES" : "NO"}\n`);
}

printer(myFavoriteMovie);
printer(myWorstMovie);

function wasMovieMadeInThe90s(year: number) : boolean
{
    if (1990 <= year && year < 2000)
    {
        return true;
    }
    return false;
}

console.log(`${myFavoriteMovie.title} ${wasMovieMadeInThe90s(myFavoriteMovie.year) ? "was" : "wasn't"} made in the 90s\n`);

function fakeScore(movie: Movies, score : number)
{
    movie.metascore = score;
}

fakeScore(myWorstMovie, 8);

printer(myWorstMovie);