cls

javac -cp "./source" ./source/local/arch/domain/ICalculator.java
javac -cp "./source" ./source/local/arch/domain/calculator/Calculator.java
javac -cp "./source" ./source/local/arch/domain/Factory.java


javac -cp "./source" ./source/local/arch/application/IService.java
javac -cp "./source" ./source/local/arch/application/IStorage.java
javac -cp "./source" ./source/local/arch/application/IStorageUsing.java
javac -cp "./source" ./source/local/arch/application/service/Service.java
javac -cp "./source" ./source/local/arch/application/Factory.java


javac -cp "./source" ./source/local/arch/infrastructure/out/storage/Mock.java
javac -cp "./source" ./source/local/arch/infrastructure/out/storage/Factory.java


javac -cp "./source" ./source/local/arch/infrastructure/in/controller/rest/endpoint/Method.java
javac -cp "./source" ./source/local/arch/infrastructure/in/controller/rest/endpoint/Request.java
javac -cp "./source" ./source/local/arch/infrastructure/in/controller/rest/endpoint/Response.java
javac -cp "./source" ./source/local/arch/infrastructure/in/controller/rest/endpoint/IController.java
javac -cp "./source" ./source/local/arch/infrastructure/in/controller/rest/endpoint/IFactory.java

javac -cp "./source" ./source/local/arch/infrastructure/in/controller/rest/endpoint/root/Controller.java
javac -cp "./source" ./source/local/arch/infrastructure/in/controller/rest/endpoint/root/Factory.java

javac -cp "./source" ./source/local/arch/infrastructure/in/controller/rest/endpoint/calculation/Controller.java
javac -cp "./source" ./source/local/arch/infrastructure/in/controller/rest/endpoint/calculation/Factory.java

javac -cp "./source" ./source/local/arch/infrastructure/in/controller/rest/endpoint/authentication/Controller.java
javac -cp "./source" ./source/local/arch/infrastructure/in/controller/rest/endpoint/authentication/Factory.java

javac -cp "./source" ./source/local/arch/infrastructure/in/controller/rest/Locator.java


javac -cp "./source" ./source/local/arch/infrastructure/builder/Builder.java




javac -cp "./source" ./source/local/Server.java




java -cp "./source" local.Server