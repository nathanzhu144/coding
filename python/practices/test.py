import math

base = float(raw_input('Enter initial savings:\n'))
rate = float(raw_input('Enter annual interest % rate:\n'))
years = int(raw_input('Enter years that pass:\n'))

total = base * math.pow(1 + (rate / 100), years)

print 'Savings after %d years is: %f' % (years, total)
