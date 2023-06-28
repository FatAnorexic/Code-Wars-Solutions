"""
ATM machines allow 4 or 6 digit PIN codes and PIN codes cannot contain anything but 
exactly 4 digits or exactly 6 digits.

If the function is passed a valid PIN string, return true, else return false.
Examples (Input --> Output)

"1234"   -->  true
"12345"  -->  false
"a234"   -->  false
"""

#This was a challenge for me, and initially it was a process of walking through
#each possible failure, then returning true should it pass them.
def validate_pin(pin):
    if len(pin)!=4 and len(pin)!=6:
        return False
    if not pin.isnumeric():
        return False
    if int(pin)<0:
        return False
    return True

#Seeing other solutions a better practice may be:
def validate_pin(pin):
    return len(pin) in (4,6) and pin.isdigit()