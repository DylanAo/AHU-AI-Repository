public class MainClass {
    public static void main(String args[]) {
        FamilyPerson.setSurname("李");

        FamilyPerson father, sonOne, sonTwo;
        father = new FamilyPerson();
        sonOne = new FamilyPerson();
        sonTwo = new FamilyPerson();

        father.setName("向阳");
        sonOne.setName("抗日");
        sonTwo.setName("抗战");

        System.out.println("父亲: " + FamilyPerson.surname + " " + father.name);
        System.out.println("大儿子: " + FamilyPerson.surname + " " + sonOne.name);
        System.out.println("二儿子: " + FamilyPerson.surname + " " + sonTwo.name);

        FamilyPerson.setSurname("张");

        System.out.println("父亲: " + FamilyPerson.surname + " " + father.name);
        System.out.println("大儿子: " + FamilyPerson.surname + " " + sonOne.name);
        System.out.println("二儿子: " + FamilyPerson.surname + " " + sonTwo.name);
    }
}
