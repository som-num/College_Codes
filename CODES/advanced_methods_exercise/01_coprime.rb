# Write a method, coprime?(num_1, num_2), that accepts two numbers as args.
# The method should return true if the only common divisor between the two numbers is 1.
# The method should return false otherwise. For example coprime?(25, 12) is true because
# 1 is the only number that divides both 25 and 12.

def gcd?(a,b)

  if a ==0 || b == 0
    return 0
  
  elsif a==b
    return a
  
  elsif a>b
    return gcd?(a-b, b)
  end

    return gcd?(a, b-a)
end

def coprime?(a,b)
    if gcd?(a,b) == 1
        return true
    else
        return false
    end

end

p coprime?(25, 12)    # => true
p coprime?(7, 11)     # => true
p coprime?(30, 9)     # => false
p coprime?(6, 24)     # => false
