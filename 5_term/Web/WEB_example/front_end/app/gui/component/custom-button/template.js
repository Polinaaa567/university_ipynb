export default function() {return ` 
    <style> button{
        font-size: 50px;
        padding: 10px;
        font-family:'Freestyle Script', serif;
        font-weight: bold;
        border: 5px solid rgb(72, 20, 71);
        border-radius: 10px;
        background-color: rgb(247, 185, 224);
        cursor: pointer;
    }  </style>
    
    <div>       
   <button>
    <slot></slot>  
   </button>
  </div>              
`}