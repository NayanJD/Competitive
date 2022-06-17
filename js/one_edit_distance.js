/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
 var isOneEditDistance = function(s, t) {
    let n = s.length, m = t.length;

    if(s == t){
        return false;
    }

    if(n == m){
        for(let i = 0; i < n; i++){
            let newStr = s.substring(0, i) + t.charAt(i) + s.substring(i + 1, s.length)

            if(newStr == t){
                return true;
            }
        }
        return false;
    } else if (n == m - 1){
        for(let i = 0; i < m; i++){
            let newStr = s.substring(0, i) + t[i] + s.substring(i , s.length);

            if(newStr == t){
                return true;
            }
        }

        return false;
    } else if (n - 1 == m){
        for(let i = 0; i < n; i++){
            let newStr = s.substring(0, i) + s.substring(i + 1, s.length);

            if(newStr == t){
                return true;
            }
        }

        return false;
    } else {
        return false;
    }
};

console.log('isOneEditDistance: ', isOneEditDistance('', ''))