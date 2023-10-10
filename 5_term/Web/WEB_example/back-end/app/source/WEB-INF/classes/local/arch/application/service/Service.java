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

    double[] numbers = { a, b };

    ICalculator calculator = Factory.createCalculator();
    double sum = 0;

    sum = calculator.sum(numbers[0], numbers[1]);
    System.out.println(sum);

    return String.format("%s", sum);
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

  @Override
  public void useStorage(IStorage storage) {
    this.storage = storage;
  }
}