'use strict';
const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath, 'utf8').trim().split('\n');

const n = Number(input[0]);

const skills = new Array(n + 1).fill(false);
let numSkills = 0;

for(let i=1; i<=n; i++){
    const [a, b] = input[i].split(' ').map(Number);
    if(a === 0 || skills[a] || skills[b]){
        skills[i] = !skills[i];
        numSkills += 1;
    }
    console.log('skills: '+skills+', a: '+a+', b; '+b+', skills[a]: '+skills[a]+', skills[b]: '+skills[b]);
}
console.log(numSkills);