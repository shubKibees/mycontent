function loder() {
   const loder_path = document.querySelector(".loder path");
   loder_path.style.stroke = "red";
   loder_path.style.transition = "none";
   let length = loder_path.getTotalLength();
   loder_path.style.strokeDasharray = `${length} ${length}`;
   loder_path.style.strokeDashoffset = length;
   loder_path.getBoundingClientRect();
   loder_path.style.transition = "stroke-dashoffset 2s ease-in-out"; 
   loder_path.style.strokeDashoffset = 0;
}
loder();

function *gen(){
   while(true){
      yield Date.now();
      console.log('hie')
   }
}

function animate_loader(){
   const gen_it=gen();
   const val=gen_it.next().value;
   console.log(val);
}
animate_loader();

