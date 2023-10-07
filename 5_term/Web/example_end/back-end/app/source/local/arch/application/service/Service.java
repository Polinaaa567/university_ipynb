package local.arch.application.service;

import local.arch.domain.ICalculator;
import local.arch.application.IService;
import local.arch.application.IStorage;
import local.arch.application.IStorageUsing;
import local.arch.domain.Factory;

public class Service implements IService, IStorageUsing {

  private IStorage storage;
  private String login = "qwerty";
  private String password = "12345678";

  @Override
  public String calculation(double a, double b) {
    // String[] hellos = storage.reStoreGreetings();
    // String hello = "Hello";
    // if (hellos.length > 0) {
    // int v = 0;
    // if ( (variant > 0) && (variant <= hellos.length) ) {
    // v = variant-1;
    // }
    // hello = hellos[v];
    // }

    double[] numbers = { a, b };
    // storage.reStoreNumbers();

    ICalculator calculator = Factory.createCalculator();
    double sum = 0;

    sum = calculator.sum(numbers[0], numbers[1]);
    System.out.println(sum);

    return String.format("%s", sum); // hello + ": " +
  }

  @Override
  public String check(String login, String password) {
    if (login.equals(this.login) && password.equals(this.password)) {
      System.out.println("OK");
      //// проверка логина и отправка ок
      return "ok";
    }

    return "";
  }

  // @Override
  // public int updateData(double[] args) {
  // int n = 0;
  // for (double v : args) {
  // if (v != 0) {
  // n = n + 1;
  // }
  // }

  // if (n != 0) {
  // double[] numbers = new double[n];
  // int i = 0;
  // for (double v : args) {
  // if (v != 0) {
  // numbers[i] = v;
  // i = i + 1;
  // }
  // }
  // storage.storeNumbers(numbers);
  // }

  // return n;
  // }

  @Override
  public void useStorage(IStorage storage) {
    this.storage = storage;
  }
}