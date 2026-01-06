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
    let S = [];
    for(let i=0; i<h; i++) {
        S.push(input[i+1].split(''));
    }
    //console.log(h, w, S)

    const black_points = [];
    let num_black = 0;
    for(let i=0; i<h; i++) {
        for(let j=0; j<w; j++) {
            if(S[i][j] === '#') {
                black_points.push([i, j]);
                num_black += 1;
            }
        }
    }
    //console.log(black_points);

    let num_try = 1;
    let prev_explored = black_points;
    while(prev_explored.length > 0) {
        //console.log(num_try, 'th try');
        //console.log('explore about', prev_explored)
        const next_black_point = [];
        for(let i=0; i<prev_explored.length; i++) {
            const [y, x] = prev_explored[i];
            //console.log('now about', [y, x]);
            const surround_point0 = [[y-1, x], [y+1, x], [y, x-1], [y, x+1]];
            const surround_point = [];
            for(let j=0; j<surround_point0.length; j++) {
                const [yy, xx] = surround_point0[j];
                if(0 <= yy && yy < h && 0 <= xx && xx < w && S[yy][xx] == '.') {
                    surround_point.push([yy, xx]);
                }
            }
            //console.log([y, x], 'surround', surround_point);
            for(let j=0; j<surround_point.length; j++) {
                const [yy, xx] = surround_point[j];
                const ssurround_point0 = [[yy-1, xx], [yy+1, xx], [yy, xx-1], [yy, xx+1]];
                const ssurround_point = [];
                for(let j=0; j<ssurround_point0.length; j++) {
                    const [yyy, xxx] = ssurround_point0[j];
                    if(0 <= yyy && yyy < h && 0 <= xxx && xxx < w) {
                        ssurround_point.push([yyy, xxx]);
                    }
                }
                let num_surrounded = 0
                //console.log([yy, xx], 'surround', ssurround_point);
                for(let k=0; k<ssurround_point.length; k++) {
                    const [yyy, xxx] = ssurround_point[k];
                    if(S[yyy][xxx] === '#') {
                        num_surrounded += 1;
                    }
                }
                //console.log(num_surrounded);
                if(num_surrounded === 1) {
                    next_black_point.push([yy, xx]);
                    //console.log('pushed');
                }
            }
        }
        //console.log(next_black_point);
        for(let i=0; i<next_black_point.length; i++) {
            const [y, x] = next_black_point[i];
            S[y][x] = '#';
        }
        //console.log(S);
        num_black += next_black_point.length;
        prev_explored = next_black_point;
        num_try += 1;
        //console.log(num_black);
    }
    console.log(num_black);
});