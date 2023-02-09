
function performCalculations(num1, num2){
	/*WRITE YOUR CODES HERE*/
	let a = Number(num1);
	let b = Number(num2);
			
	document.getElementById('subtractionOutput').innerHTML = (num1 + " - " + num2 + " = " + diff(num1,num2))
	document.getElementById('multiplicationOutput').innerHTML = (num1 + " * " + num2 + " = " + pro(num1,num2))
	document.getElementById('divisionOutput').innerHTML = (num1 + " / " + num2 + " = " + qou(num1,num2))
}

function makeMultiplcationTable(table){            
			lami ='<table>'
			out = '<table>'
			document.getElementById('tableName').innerHTML = "TABLE OF " + table
			// let i = 0;
            // while(i <=10){
            //     let pro= table*i;		
			// 	document.getElementById('1_row').innerHTML = table + " x " + i   
			// 	document.getElementById('1_output').innerHTML =  pro 
			// 	lami = lami + '<tr><td>'+table+" x "+i+'</td></tr>';
			// 	out = out +'<tr><td>'+pro+'</td></tr>';	
			// 	i++;
            // }	
			
			 	 
			for (i=0;i<=10;i++){
				let pro = table * i
				lami +='<tr><td>'+table+" x "+i+'</td></tr>';
				out +='<tr><td>'+pro+'</td></tr>';				

			}
			document.getElementById('1_row').innerHTML = lami
			document.getElementById('1_output').innerHTML = out
			console.log(lami)
			console.log(out)
			
}


const sum = (a,b) => Number(a)+Number(b)
const diff = (a,b) => Number(a)-Number(b)
const pro = (a,b) => Number(a)*Number(b)
const qou = (a,b) => Number(a)/Number(b)

/*
<table>
<tr><td>0</td></tr>
<tr><td>1</td></tr>
<tr><td>2</td></tr>
<tr><td>3</td></tr>
<tr><td>4</td></tr>
<tr><td>5</td></tr>
<tr><td>6</td></tr>
<tr><td>7</td></tr>
<tr><td>8</td></tr>
<tr><td>9</td></tr>
<tr><td>10</td></tr>
<table>
<tr><td>0</td></tr>
<tr><td>1</td></tr>
<tr><td>2</td></tr>
*/