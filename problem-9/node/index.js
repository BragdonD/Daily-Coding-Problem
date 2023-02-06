// Adjacent number : example 1 & 3 are adjacent throught 2

function get_highest_sum(arr) {
    if(arr.length == 0) return 0;
    if(arr.length == 1) return arr[0];
    if(arr.length == 2) return Math.max(...arr);

    let prev1 = 0;
    let prev2 = 0;

    for(const nb of arr) {
        current = Math.max(prev1, nb + prev2)
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

console.log(get_highest_sum([2, 4, 6, 2, 5]))