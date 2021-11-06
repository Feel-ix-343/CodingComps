import java.util.Scanner
// object Main {
//  def main (args: Array[String]) {...}
// }
object Main extends App {
  // val num = new Scanner(System.in).nextLine()
  // val num = io.StdIn.readLine("Input a number: ")
  val num = "123321"
  def countDigits(i: String): Int = num.length // I don't actually need to specify return type
  def sumFirstLast(i: String): Int = Integer.parseInt(i.substring(0, 1)) + Integer.parseInt(i.substring(i.length - 1))
  def swapFirstLast(i: String): String = i.substring(i.length - 1) + i.substring(1, i.length - 1) + i.substring(0, 1)
  def calcSum(i: String): Int = i.split("").map(Integer.parseInt).sum
  def calcProduct(i: String): Int = i.split("").map(Integer.parseInt).product // or ...reduce(_ * _) or ...reduce(x => x * x) or reduce((x: Int) => x * x)
  def reverseNum(i: String): String = i.reverse
  def isPalindrome(i: String): Boolean = i == i.reverse // or ... == reverseNum(i)
  def frequencyOfDigits(i: String): String = (for (x <- i.split("").toSet.toArray) yield x + ": " + i.count(_ == x.charAt(0)) + " times").mkString(", ")

  println(countDigits(num))
  println(sumFirstLast(num))
  println(swapFirstLast(num))
  println(calcSum(num))
  println(calcProduct(num))
  println(reverseNum(num))
  println(isPalindrome(num))
  println(frequencyOfDigits(num))
}
