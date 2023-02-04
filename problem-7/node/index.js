const keys = {
    'a': 1,
    'b': 2,
    'c': 3,
    'd': 4,
    'e': 5,
    'f': 6,
    'g': 7,
    'h': 8,
    'i': 9,
    'j': 10,
    'k': 11,
    'l': 12,
    'm': 13,
    'n': 14,
    'o': 15,
    'p': 16,
    'q': 17,
    'r': 18,
    's': 19,
    't': 20,
    'u': 21,
    'w': 22,
    'v': 23,
    'x': 24,
    'y': 25,
    'z': 26,
}
/*
1213 -> 1 2 1 3 -> always 1
     -> 12 1 3
     -> 12 13
     -> 1 2 13
     -> 1 21 3
     -> 1 2 3 12 13 21 
     
1213 ->  1 -> 2 -> 1 -> 3
     |     |   |-> 13   
     |     |->21
     |-> 12 -> 1 -> 3
           |-> 13
First we can always split with 1 token
The problem is harder to split on 2 tokens
*/

/**
 * 
 * @param {String} str 
 * @returns 
 */
function get_possibilities(str) {
    if(str.length == 0) return 0;
    if(str[0] == '0') return 0;
    if(str.length == 1) return 1;
    
    let possibilities = 0;

    if( Object.keys(keys).find(key => keys[key].toString() === (str[0] + str[1])) ) {
        if(str.length == 2) {
            possibilities ++;
        }
        possibilities += get_possibilities(str.slice(2));
    }
    possibilities += get_possibilities(str.slice(1));

    
    return possibilities;
}

console.log(get_possibilities("101"));