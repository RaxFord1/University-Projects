var canvas;
var ctx;
function normalize (value, in_min, in_max, out_min, out_max) {
  return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
Array.max = function(array){
    return Math.max.apply( Math, array );
};
    
Array.min = function(array){
    return Math.min.apply( Math, array );
};

var lower, upper, step;
function call(){
    lower = parseInt(document.getElementById("lower").value);
    upper = parseInt(document.getElementById("upper").value);
    step = parseFloat(document.getElementById("step").value);

    let select = document.getElementById('cycle_type');
    let type = select.options[select.selectedIndex].value;
    
    let values; 
    if (type == "For"){
        values = calc_for();
    } else if (type == "While"){
        values = calc_while();
    } else {
        values = calc_do_while();
    }
    console.log("values:",values);
    tabulate(values);
}
function calc_for(){
    console.log("Doing for");
    let values = [];

    for (x = lower; x <= upper; x = x + step){
        y = 1000*(Math.abs(x-1));
        values.push(y);
    }
    return values
}
function calc_while(){
    console.log("Doing while");
    let values = [];
    let x = lower;
    while (x<=upper){
        y = 0.005*(0.2*x**2)**2;
        values.push(y);
        x = x + step;
    }
    return values;
}

function calc_do_while(){
    console.log("Doing do_while");
    let values = [];
    x = lower;
    do {
        y = 0.005*(0.2*x**2)**2;
        values.push(y);
        x+=step;
    } while(x<=upper);
    return values;
}

function tabulate(values){
    
    if (lower > upper){
        alert("Lower > upper");
        return;
    }

    canvas = document.getElementById("сanvas"); // Отримання canvas елемента
    
    ctx = canvas.getContext('2d'); // Тип рисування
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    let max_width = canvas.width;
    let max_height = canvas.height;

    ctx.fillStyle = "red"; // Колір рисування
    ctx.beginPath();

    let x = lower;
    let y = 0;
    
    

    i=0;
    max_value = Array.max(values);
    min_value = Array.min(values);
    console.log( "min, max, width, height", min_value, max_value, max_height, max_width );

    for (x = lower; x < upper; x = x + step){
        i++;
        val = values[i];
        prev_val = values[i-1];
        //console.log(val, prev_val);

        prev_val = normalize(prev_val, min_value, max_value, 0, max_height);
        val = normalize(val, min_value, max_value, 0, max_height);
        //console.log("*",val, prev_val);
        
        x1 = normalize(x, lower, upper, 0, max_width);
        x2 = normalize(x+step, lower, upper, 0, max_width);
        ctx.moveTo(x1, prev_val);

        ctx.lineTo(x2, val);
        ctx.stroke();
    }
}