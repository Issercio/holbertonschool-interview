#!/usr/bin/node
const request = require('request');

if (process.argv.length < 3) {
  console.error('Usage: ./0-starwars_characters.js <Movie ID>');
  process.exit(1);
}

const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(url, (err, res, body) => {
  if (err) {
    console.error(err);
    process.exit(1);
  }
  const film = JSON.parse(body);
  const characters = film.characters;
  if (!characters) {
    process.exit(1);
  }
  const getCharacter = (idx) => {
    if (idx >= characters.length) return;
    request(characters[idx], (err, res, body) => {
      if (err) {
        console.error(err);
        process.exit(1);
      }
      const character = JSON.parse(body);
      console.log(character.name);
      getCharacter(idx + 1);
    });
  };
  getCharacter(0);
});
