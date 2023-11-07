var personDetail=["Ramlesh Singh","Ranjeet Singh","Anand K Singh","Ankur Goel","Vishesh Kumar Bhatia","Rishabh Kapoor","Manoj Gulati","Abhishek K Singh","Ashutosh Dubey","Ankit Sharma","Yunus Khan","Anupam Mahendru","Virendra Dhariwal","Amit Nanchahal","Vikas Gupta","Manoj Sangar","Vijay Verma","Rahul Dixit","Shivanshu Tyagi","Naheed Akhter","Jaspreet Singh Lamba","Udayan Banerjee","Suvrendu Mitra","Saptarshi Bhandari","Inderjit Yadav","Vir Vijay","Biswajit Ghosh","Sagnik Kar","Pinaki Choudhury","Satender Yadav","Gautam Deb","Dinesh Kumar Singh","Loknath Khanal","Lokesh Nath","HB Parida","Bharat K SIngh","Pankaj Das","Dipankar Mahanta","Pritam Chakraborty","Rajnish Rai","Kamal Gohil","Sameer Kenia","Rajesh Phatangare","Animesh B","Sanjeev Pathak","Pankaj Shukla","Ashish Fotedar","Kelvin G","Rahim Nadaf","Firoz Sayyad","Lokesh BS","Ajay Chawla","Raj Tiwari","Saurabh Shah","Prashant Bhojne","Sujay Sharma","Rakesh Kaurav","Karan D","Ratnesh Gautam","Arvind Kalchuri","Brajesh Katare","Abhishek Jadhav","B Dileep","Sanee","Deepu James","Ranadheer Reddy","Veerandra Krishna","Pasupulati Pramod K","Prakash Chandana","Vinay Kumar B R","Snehasis Mohanty","Yuvraj Dilip Hangirgekar","Krishna Kiran","Pinnamaneni Naveen","Sujesh Soman","Jagan George","Rajesh S","Anoop R S","Shankar D","Gangadharan M","Mudari Satyanarayana","Sarath Nath","A Shiva Kumar","Al Subramanian","Yuvaraj S"]
class node{
   constructor(map_char=new Map(),endWord=false){
      this.map_char=map_char;
      this.endWord=endWord;
   }
}

class tree {
   constructor(storage) {
     this.root = new node();
     this.words = []; 
     this.storage=storage;
     this.createTree();
   }
 
   insert(word) {
     let temp = this.root;
     for (let char of word) {
       if (!temp.map_char.has(char)) {
         temp.map_char.set(char, new node());
       }
       temp = temp.map_char.get(char);
     }
     temp.endWord = true;
   }
 
   ifPrefixExist(prefix) {
     let temp = this.root;
     for (let char of prefix) {
       if (!temp.map_char.has(char)) {
         return false;
       }
       temp = temp.map_char.get(char);
     }
     this.words = []; 
     this.allWordwithPrefix(prefix, temp);
     return this.words;
   }
 
   allWordwithPrefix(prefix, startNode, currentWord = '') {
     if (startNode.endWord) {
       this.words.push(prefix + currentWord);
     }
     for (let [key, value] of startNode.map_char) {
       this.allWordwithPrefix(prefix, value, currentWord + key);
     }
   }
   createTree(){
      for(let i=0;i<this.storage.length;i++){
         this.insert(this.storage[i]);
      }
      console.log("tree created again")
   }
 }

var createSearchTree=new tree(personDetail);
const input_search=document.getElementById("inputSearch");
const search_box=document.getElementById("searchResult");
input_search.addEventListener("input",function(){
   var search_result=createSearchTree.ifPrefixExist(input_search.value);
   search_box.innerHTML="";
   if(search_result.length>0){
     search_result.forEach((txt)=>{
        search_box.appendChild(createLabel(txt));
     }) 
   }
   else{
      search_box.appendChild(createLabel("No Result Found"));
   }
})


var box=document.getElementById("searchResult");
box.addEventListener("click",function(e){
   var target=e.target;
   if(target.tagName=="P"){
      input_search.value=target.innerHTML;
      
   }
})


// input_search.addEventListener("input",function(){
//   search_box.innerHTML="";
//   personDetail.forEach((detail)=>{
//      if(detail.includes(input_search.value)){
//       search_box.appendChild(createLabel(txt));
//      }
//      else{
//       search_box.appendChild(createLabel("No Result Found"));
//      }
//   })
// })

function createLabel(text){
   var label=document.createElement("p");
   label.innerHTML=text;
   return label;
}