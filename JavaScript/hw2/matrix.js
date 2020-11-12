let x = 10;
let y = 10;

var arr = Array.from(Array(x), () => new Array(y));
let cnt = 1;

for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
        arr[i][j] = cnt;
        cnt++;
    }
}

for (let i = 0; i < x; i++) {
    for (let j = 0; j < y; j++) {
        if (i !== j)
            arr[i][j] = '-';
    }
    console.log(arr[i].join(' '));
}


