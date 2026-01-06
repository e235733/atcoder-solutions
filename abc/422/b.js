'use strict';

const fs = require('fs');
const readline = require('readline');

const isAtCoder = process.platform === 'linux';

const inputStream = isAtCoder
    ? process.stdin
    : fs.createReadStream('./input.txt');

const rl = readline.createInterface({
    input: inputStream,
});

const input = [];
rl.on('line', (line) => {
    input.push(line);
});

rl.on('close', () => {
    const [h, w] = input[0].split(' ').map(Number);
    const S = input.slice(1);
    //console.log(S[2][1]);
    for(let i=0; i<h; i++){
        for(let j=0; j<w; j++){
            //console.log('now on S['+i+']['+j+']: '+S[i][j]);
            if(S[i][j] === '#'){
                let sumSurroundBlack = 0;
                //周囲のインデックス
                const surroundIndex = [[i, j-1], [i, j+1], [i-1, j], [i+1, j]];
                for(let k=0; k<4; k++){
                    const nextIndex = surroundIndex[k];
                    //console.log('.   nextIndex; '+nextIndex[0]+' '+nextIndex[1]);
                    const nextFlag = nextIndex[0] >= 0 && nextIndex[0] < h && nextIndex[1] >= 0 && nextIndex[1] < w;
                    //console.log('.   isExist: ' + nextFlag);
                    if(nextFlag){
                        //console.log('.       look surround S['+nextIndex[0]+']['+nextIndex[1]+']: '+S[nextIndex[0]][nextIndex[1]]);
                        if(S[nextIndex[0]][nextIndex[1]] === '#'){
                            sumSurroundBlack += 1;
                        }
                    }
                }
                if(sumSurroundBlack != 2 && sumSurroundBlack != 4){
                    console.log('No');
                    return;
                }
            }
        }
    }
    console.log('Yes');
});