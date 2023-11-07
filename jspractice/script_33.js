var progress_score=100;
var interval_pointer;
const progress_bar=document.querySelector(".progress");

const button_start=document.querySelector("#start");
const button_stop=document.querySelector("#stop");
const button_reset=document.querySelector("#reset");
button_start.addEventListener("click",()=>{
      interval_pointer=setInterval(()=>{
         progress_score=progress_score-2;
         progress_bar.style.right=(progress_score%100)+"%";
         if(progress_score==0){
            clearInterval(interval_pointer);
            progress_score=0;
            progress_bar.style.right=progress_score+"%";
            return;
         }
      },100)
})
button_stop.addEventListener("click",()=>{
   clearInterval(interval_pointer);
})
button_reset.addEventListener("click",()=>{
   progress_score=100;
   progress_bar.style.right=progress_score+"%";
   clearInterval(interval_pointer);
})

