# Oppgave 3:
gangetall = int(input("Kva for eit tall vil du finne gangetabellen til? "))

gangetabellen = []
for i in range(1,11):
  gangetabellen.append(gangetall*i)
    
print(gangetabellen)
    
#Oppgave 4:

def f(x):
    return x**2 - 4*x +1

minste = int(input("Kva er den minste verdien for x? "))
største = int(input("Kva er den største verdien for x? "))
steglengde = int(input("Kva er steglengden til x? "))
yverdier = []
xverdier = []
for i in range (minste, største, steglengde):
    yverdier.append(f(i))
    xverdier.append(i)
    
print("x-verdiene =", xverdier, "y-verdiene =", yverdier)

#Oppgave 5:
tall = int(input("Kva er tallet du vil finne minste tverrsum av? "))

def tverrsum (tall):
    tverr = 0
    alle_tverr = 0
    tall = str(tall)
    for i in range(len(tall)):
        tverr = str(tall[i])
        alle_tverr += int(tverr)
    tall = int(alle_tverr)
    return tall


while tall >= 10:
    print("Tversummen til ", tall, "er", (tverrsum(tall)))
    tall = tverrsum(tall)
    

    
 
