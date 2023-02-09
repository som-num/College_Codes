{
  let hr = document.querySelector("#hr");
  let mn = document.querySelector("#mn");
  let sc = document.querySelector("#sc");

  setInterval(() => {
    let day = new Date();
    let hh = day.getHours() * 30;
    let mm = day.getMinutes() * 6;
    let ss = day.getSeconds() * 6;

    hr.style.transform = `rotateZ(${hh + mm / 12}deg)`;
    mn.style.transform = `rotateZ(${mm}deg)`;
    sc.style.transform = `rotateZ(${ss}deg)`;
  });
} // analog clock ni

{
// set audio for alarm
let audio = new Audio();
audio.src = 'scream.mp3';
audio.loop = true;


let alarmTime = null;
let alarmTimeout = null;
let alarmCount = 0;

let myList = document.querySelector('#myList');
let addAlarm = document.querySelector('.setAlarm')


let alarmList = [];  // Stores all the alarms being set

// Plays the alarm audio at correct time
function ringing(now){
    audio.play(now);
    window.alert(`Hey! it is ${now}`)
}

// updates time every second 
function updateTime() {
    var today = new Date();
    
    let hour = formatTime(today.getHours());
    let hour24 = formatTime(today.getHours());
    let hour12 = formatTime(today.getHours()%12||12);
    let minutes = formatTime(today.getMinutes());
    let seconds = formatTime(today.getSeconds());
    let milsecs = formatTime(today.getMilliseconds()/ 10 | 0);
    
    let ampm = document.getElementById('ampm').value;
    let newam24 = hour >= 12 ? "PM" : "AM";
    
    let now12=`${hour12}:${minutes}:${seconds} ${newam24}`;
    let now24=`${hour24}:${minutes}:${seconds} ${newam24}`;
   
 
    let x = document.getElementById('tfourHour').value;
    
    //for hour format
   switch(x){
     case "12":
       document.getElementById('clock').innerHTML=`${hour12}:${minutes}:${seconds}:${milsecs} ${newam24}`
       break;
     case "24":
       document.getElementById('clock').innerHTML =`${hour24}:${minutes}:${seconds}:${milsecs} ${newam24}`
       break;
     default:
     break;
   }
   
//     check if the alarmList includes the current time , "now"
//     if yes, ringing() is called
    if(alarmList.includes(now12)){
        ringing(now12);
    } 
    else if (alarmList.includes(now24)) {
      ringing(now24);
    } 
}


// set the correct format of time
// converts "1:2:3" to "01:02:03"
function formatTime(time) {
    if ( time < 10 && time.length != 2) {
        return '0' + time;
    }
    return time;
}


// function to clear/stop the currently playing alarm
function clearAlarm() {
    audio.pause();
    audio.currentTime = 0;
    if (alarmTimeout) {
        alert('Alarm cleared');
    }
}


// removes an alarm from the unordered list and the webpage when "Delete Alarm" is clicked
myList.addEventListener('click', e=> {
    console.log("removing element")
    if(e.target.classList.contains("deleteAlarm")){
        e.target.parentElement.remove();
    }    
});


// removes an alarm from the array when "Delete Alarm" is clicked

function remove(click_id){
  var element = document.getElementById("alarm"+click_id);
    var deleteIndex = alarmList.indexOf(document.querySelector("#span"+click_id).innerText);
    alarmList.splice(deleteIndex,1);
    element.remove();
    console.log(element)
    console.log(alarmList)
};

// Adds newAlarm to the unordered list as a new list item on webpage
function showNewAlarm(newAlarm){
  alarmCount++;
  const html= 
  `
  <div class="time-list" id="alarm${alarmCount}">
   <span id="span${alarmCount}">${newAlarm}</span>
   <button class="btn-delete" id="${alarmCount}" onClick="remove(this.id)">Delete</button>
  </div>
  `;
myList.innerHTML += html;
};


// event to set a new alarm whenever the form is submitted 
addAlarm.addEventListener('submit', e=> {
    e.preventDefault();
    // const newAlarm = addAlarm.alarmTime.value;
    
    let new_h=formatTime(addAlarm.a_hour.value);
    if(new_h === '0'){
        new_h = '00'
    }
    let new_m=formatTime(addAlarm.a_min.value);
    if(new_m === '0'){
        new_m = '00'
    }
    let new_s=formatTime(addAlarm.a_sec.value);
    if(new_s === '0'){
        new_s = '00'
    }
    

    let new_ampm=formatTime(addAlarm.ampm.value);
   
    
    const newAlarm = `${new_h}:${new_m}:${new_s} ${new_ampm}`;
    

//     add newAlarm to alarmList
    if(isNaN(newAlarm)){

        if(!alarmList.includes(newAlarm)){
            alarmList.push(newAlarm);
            console.log(alarmList);
            console.log(alarmList.length);
            showNewAlarm(newAlarm);
            addAlarm.reset();
        } else{
            alert(`Alarm for ${newAlarm} already set.`);
        }
    } else{
        alert("Invalid Time Entered")
    }        
})
// calls updateTime() every second
setInterval(updateTime, 0);
} // alarm

{
// Stopwatch na ta brod
let milliseconds =0;
let seconds = 0;
let minutes = 0;
let hours = 0;

let displayMilliseconds =0;
let displaySeconds = 0;
let displayMinutes = 0;
let displayHours =  0;

let status = 'Stopped';
let interval = '';

function StartWatch()
{  milliseconds++;
  
 if(milliseconds/99 == 1)
  {
   milliseconds=0;
   seconds++;

	if(seconds/60 === 1)
	  {
		seconds=0;
		minutes++;
	  }
		if(minutes/60 === 1)
		{
			minutes=0;
			hours++;
		}
	}

  if(milliseconds < 10 )
	{
		displayMilliseconds = '0' + milliseconds.toString();
	}
	else
	{
		displayMilliseconds = milliseconds;
	}
	if(seconds < 10 )
	{
		displaySeconds = '0' + seconds.toString();
	}
	else
	{
		displaySeconds = seconds;
	}

	if(minutes < 10 )
	{
		displayMinutes = '0' + minutes.toString();
	}
	else
	{
		displayMinutes = minutes;
	}

	if(hours < 10 )
	{
		displayHours = '0' + hours.toString();
	}
	else
	{
		displayHours = hours;
	}

	document.getElementById('swatchdisplay').innerHTML = displayHours + ":" + displayMinutes + ":" + displaySeconds + ":" +displayMilliseconds;
}

function startStop()
{
	if(status == 'Stopped')
	{
		interval = window.setInterval(StartWatch,5);
		document.getElementById('handler').innerHTML = 'Stop';
		status = 'Started';
	}
	else if(status == 'Started')
	{
		window.clearInterval(interval);
		document.getElementById('handler').innerHTML = 'Start';
		status = 'Stopped';
	}
}

function Reset()
{
  milliseconds = 0;
	seconds = 0;
	hours = 0;
	minutes = 0;
	window.clearInterval(interval);
  document.getElementById('lapShow').innerHTML= "";
	document.getElementById('swatchdisplay').innerHTML = '00:00:00:00';
	document.getElementById('handler').innerHTML = 'Start';
	status = 'Stopped';
    }

function lap(){
  document.getElementById('lapShow').innerHTML +=  `${displayHours}: ${displayMinutes}: ${displaySeconds}: ${displayMilliseconds} <br>`
  }
}// stopwatch

{
let audio = new Audio();
audio.src = 'scream.mp3';
audio.loop = false;

var start = document.getElementById('start');
var reset = document.getElementById('reset');
var stop = document.getElementById('stop');
/*var timer = null,
  interval = 1000,
  value = 0;*/
  
var h = document.getElementById("hour");
var m = document.getElementById("minute");
var s = document.getElementById("sec");
var ms = document.getElementById("milsec");

//storing variable
var startTimer = null;

start.addEventListener('click', function(){
    //start timer
    function startInterval(){
        startTimer = setInterval(function() {
            timer();
        }, 10);
    }
    startInterval();
});

reset.addEventListener('click', function(){
    h.value = 0;
    m.value = 0;
    s.value = 0;
    ms.value = 0;
  audio.pause();
    //stop the timer
    stopInterval()
});

stop.addEventListener('click',function(){
  clearInterval(startTimer,1);
  audio.pause();
  
 /*startTimer = clearInterval(function() {
            startTimer=null;
        }, 5);*///dimugana
});


function timer(){

    if(h.value == "0" && m.value == "0" && s.value == "0" && ms.value == "0"){
    //window.alert(' Time na Goyyy!!! ');
    window.open("https://www.cornhub.com")
    audio.play();
    stopInterval();
  } else if (h.value == 0 && m.value == 0 && s.value == 0 && ms.value == 0) {
  } else if (ms.value != 0) {
    ms.value--;
  } else if (s.value != 0 && ms.value == 0) {
    ms.value = 99;
    s.value--;
  } else if (m.value != 0 && s.value == 0) {
    s.value = 59;
    m.value--;
  } else if (h.value != 0 && m.value == 0) {
    m.value = 60;
    h.value--;
  }
    return;
}

//stop the function after pressing the reset button, 
//so the time will not go down when selecting a new time after pressing reset
function stopInterval() {
    clearInterval(startTimer);
}

  
} // countdown

{
let popupSW = document.getElementById("popupSW");

function openPopupSW(){
  popupSW.classList.add("open-popup");
}
function closePopupSW(){
  popupSW.classList.remove("open-popup");
}


let popupCD = document.getElementById("popupCD");

function openPopupCD(){
  popupCD.classList.add("open-popup");
}
function closePopupCD(){
  popupCD.classList.remove("open-popup");
}
}//popup box
