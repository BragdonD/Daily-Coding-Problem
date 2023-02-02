function get_ouput(arr) {
    arr = arr.filter(elem => elem > 0)  // O(n)
    arr.sort();                         // O(n)
    for(let i=0; i < arr.length; i++) { // O(n)
        if(arr[i] != i+1) return i + 1;
    }
    return arr[arr.length - 1] + 1;
}

console.log(get_ouput([3, 4, -1, 1])) // Expect 2
console.log(get_ouput([1, 2, 0])) // Expect 3