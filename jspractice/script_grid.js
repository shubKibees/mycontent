const grid_cont=document.querySelector(".grid")
const container=document.querySelector(".container")
function div_create(text,size){
    const div=document.createElement("div")
    div.classList.add("grid-item")
    div.innerHTML=text
    div.style.width=`${block_square}px`
   div.style.height=`${block_square}px`
   div.classList.add("block");
   div.setAttribute(`data-position`,index);
   div.style.backgroundColor=`rgb(${Math.floor(Math.random()*255)},${Math.floor(Math.random()*255)},${Math.floor(Math.random()*255)})`
    return div    
}

var width=container.getBoundingClientRect().width;
var height=container.getBoundingClientRect().height;
var index=0;
var no_of_blocks_in_row=0;
const block_square=100;
while(width>=0||height>=0){
   const div=div_create(`${index}`,block_square)
   grid_cont.appendChild(div)
   index++;
   width-=block_square;
   if(width<=0&&height>=0){
      height-=block_square;
      if(!no_of_blocks_in_row){
         no_of_blocks_in_row=index-1;
      }
      width=container.getBoundingClientRect().width-block_square;
   }
}

function findDimension(origin,no_of_block_within_row){
   let x=origin%no_of_block_within_row;
   let y=Math.floor(origin/no_of_block_within_row);
   let top=(y-1)*no_of_block_within_row+x;
   let bottom=(y+1)*no_of_block_within_row+(x);
   let left=y*no_of_block_within_row+(x-1);
   let right=y*no_of_block_within_row+(x+1);
   return[
      origin,top,bottom,left,right]
}

container.addEventListener("mouseover", (e) => {
   if (e.target.classList.contains("block")) {
      let dimension = findDimension(e.target.getAttribute("data-position"), no_of_blocks_in_row);
      console.log(`dimension: ${dimension}`)
      for (let index of dimension) {
         let element = document.querySelector(`[data-position="${index}"]`);
         element.classList.add("animate"); 
      }
   }
});

container.addEventListener("mouseout", (e) => {
   if (e.target.classList.contains("block")) {
      let dimension = findDimension(e.target.getAttribute("data-position"), no_of_blocks_in_row);
      for (let index of dimension) {
         let element = document.querySelector(`[data-position="${index}"]`);
         element.classList.remove("animate"); 
      }
   }
});



