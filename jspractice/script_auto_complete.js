var personDetail=["Ramlesh Singh","Ranjeet Singh","Anand K Singh","Ankur Goel","Vishesh Kumar Bhatia","Rishabh Kapoor","Manoj Gulati","Abhishek K Singh","Ashutosh Dubey","Ankit Sharma","Yunus Khan","Anupam Mahendru","Virendra Dhariwal","Amit Nanchahal","Vikas Gupta","Manoj Sangar","Vijay Verma","Rahul Dixit","Shivanshu Tyagi","Naheed Akhter","Jaspreet Singh Lamba","Udayan Banerjee","Suvrendu Mitra","Saptarshi Bhandari","Inderjit Yadav","Vir Vijay","Biswajit Ghosh","Sagnik Kar","Pinaki Choudhury","Satender Yadav","Gautam Deb","Dinesh Kumar Singh","Loknath Khanal","Lokesh Nath","HB Parida","Bharat K SIngh","Pankaj Das","Dipankar Mahanta","Pritam Chakraborty","Rajnish Rai","Kamal Gohil","Sameer Kenia","Rajesh Phatangare","Animesh B","Sanjeev Pathak","Pankaj Shukla","Ashish Fotedar","Kelvin G","Rahim Nadaf","Firoz Sayyad","Lokesh BS","Ajay Chawla","Raj Tiwari","Saurabh Shah","Prashant Bhojne","Sujay Sharma","Rakesh Kaurav","Karan D","Ratnesh Gautam","Arvind Kalchuri","Brajesh Katare","Abhishek Jadhav","B Dileep","Sanee","Deepu James","Ranadheer Reddy","Veerandra Krishna","Pasupulati Pramod K","Prakash Chandana","Vinay Kumar B R","Snehasis Mohanty","Yuvraj Dilip Hangirgekar","Krishna Kiran","Pinnamaneni Naveen","Sujesh Soman","Jagan George","Rajesh S","Anoop R S","Shankar D","Gangadharan M","Mudari Satyanarayana","Sarath Nath","A Shiva Kumar","Al Subramanian","Yuvaraj S"]


class Node {
   constructor(children = new Array(27).fill(null), endOfWord = false) {
      this.children = children;
      this.endOfWord = endOfWord;
   }
}

class Tree {
   constructor(stroage) {
      this.root = new Node();
      this.allWords = [];
      this.stroage=stroage;   
      this.createTree();   
   }

   insert(word) {
      let temp = this.root;
      word = word.toLowerCase();
      for (let char of word) {
         let index;
         if (char === ' ') {
            index = 26; 
         } else {
            index = char.charCodeAt(0) - 97;
         }
         if (temp.children[index] === null) {
            temp.children[index] = new Node();
         }
         temp = temp.children[index];
      }
      temp.endOfWord = true;
   }

   searchWithPrefixExist(prefix) {
      let temp = this.root;
      this.allWords = [];
      for (let char of prefix) {
         let index;
         if (char === ' ') {
            index = 26; 
         } else {
            index = char.charCodeAt(0) - 97;
         }
         if (temp.children[index] === null) {
            return [];
         }
         temp = temp.children[index];
      }
      this.allWordsWithPrefix(prefix, temp);
      return this.allWords;
   }

   allWordsWithPrefix(word, lastNode) {
      if (lastNode.endOfWord) {
         this.allWords.push(word);
      }
      for (let i = 0; i < lastNode.children.length; i++) {
         let nodeExist = lastNode.children[i];
         if (nodeExist !== null) {
            if (i === 26) {
               this.allWordsWithPrefix(word + ' ', nodeExist);
            } else {
               this.allWordsWithPrefix(word + String.fromCharCode(i + 97), nodeExist);
            }
         }
      }}
   createTree(){
      for(let i=0;i<this.stroage.length;i++){
         this.insert(this.stroage[i]);
      }
   }
}


var createSearchTree=new Tree(personDetail);

const input_search=document.getElementById("inputSearch");
const search_box=document.getElementById("searchResult");
input_search.addEventListener("input",function(){
   var search_result=createSearchTree.searchWithPrefixExist(input_search.value);
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


function createLabel(text){
   var label=document.createElement("p");
   label.innerHTML=text;
   return label;
}



