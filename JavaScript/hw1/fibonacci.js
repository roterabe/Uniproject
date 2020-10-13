function fib(n) {
    if (n < 2) {
        return n;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

for (let i = 5; i < 15; i++) {
    console.log(fib(i+1) + " ");
}
