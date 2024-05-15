def factorial(n):
   if n < 1:   # base case
       return 1
   else:
       returnNumber = n * factorial(n - 1)  # recursive call
       print(str(n) + '! = ' + str(returnNumber))
       return returnNumber
       

print(factorial(5))
