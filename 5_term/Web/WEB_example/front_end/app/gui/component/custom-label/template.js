console.log('Log:Exporting template for x-label');

export default function() {return `  
<style> 
H1 {
  font-family:'Freestyle Script', serif;
  text-align: center;
  margin: 100px 10px;
  font-size: 100px;
  color: rgb(231, 63, 172);
  text-shadow: 0px 0px 5px rgb(72, 20, 71);
}  
</style> 
  <div> 
    <slot></slot>  
  <br>
  <H1>
  User:  ${vm._xUser}
  <br> 
  Всего задач: ${vm._quantityTasks}
  <br>
  Задач выполнено: ${vm._doneTasks}
  <br>
  Задач обрабатываются: ${vm._performTasks}
  <br>
  Пустых задач: ${vm._emptyTasks}
  </H1> 
  </div>
`}