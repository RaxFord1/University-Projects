function randomIntFromInterval(min, max) { // min and max included 
    return Math.floor(Math.random() * (max - min + 1) + min)
  }
function convertArrayToString(arr) {
    let str = "[";
    arr.forEach(element => {
        str += " " + element+",";
    })
    str+=" ]";
    return str;
}
function replaceValuesLssThanZero(){
    let str;
    var N = 100;
    let min_max = 1000
    var arr = [];
    for (let i = 0; i < N; i++){
        arr.push(randomIntFromInterval(-min_max, min_max));
    }
    
    str = convertArrayToString(arr);
    document.getElementById("before").innerHTML = str;
    for (let i = 0; i < N; i++){
        if (arr[i]<0){
            arr[i]=0;
        }
    }
    str = convertArrayToString(arr);
    document.getElementById("after").innerHTML = str;
}
replaceValuesLssThanZero();