#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon May 25 10:33:06 2020

@author: evatimothy
"""


#-----------------------------------------------------------
# Lecture 15 -- Scipy Optimization for NLEs
#-----------------------------------------------------------

import numpy as np
import matplotlib.pyplot as plt

# Scipy is a module library that works with Numpy and Matplotlib to enable
# numerical calculations.
# * Numpy -- Arrays and matrices
# * Matplotlib -- Plotting
# * Scipy -- Numerical tools for Scientific/Engineering Calculations
#
# * "minimize" is the nonlinear optimization tool in Scipy

import scipy.optimize as opt

# %%
#-----------------------------------------------------------
# A. Single Equations (1 equation, 1 unknown)
#-----------------------------------------------------------

# Steps to solving a single nonlinear equation using root:
# (1) import module: import scipy.optimize as opt
# (2) Put the equation in residual form, f(x) = 0
# (3) Define a python function for the **objective function**
#       def <fn name> (<args>): 
#           residual = <f(x) function>
#           return residual**2
# (4) Set an initial guess for x
# (5) Call `minimize` function: x = minimize(<fn name>, <guess>).x
#       ** Note: Just like root, minimize returns a "dictionary." So you need
#          to put the .x after the function call. If not, you will get a 
#          whole bunch of extra info. Also, the answer (even if it just a 
#          single equation) will be stored in a numpy array.
#
# Additional information about root at the link:
#   https://docs.scipy.org/doc/scipy/reference/generated/scipy.optimize.minimize.html
# ----------
# Example 
# ----------
# Solve x^2 +x - 5 = 0

def S(x):
    res = x**2 + x - 5
    return res**2

x_plt = np.linspace(-4, 3)
plt.rc("font", size=14)
plt.figure()
plt.plot(x_plt, S(x_plt), 'k-')
plt.plot([-4, 3], [0, 0], 'r--')

xguess = 2.
x1 = opt.minimize(S,xguess).x
print('Example 1')

print("x =", x1)
print("Objective Function = ", S(x1))

plt.plot(x1, S(x1), 'bo')

# ----------
# Practice 
# ----------
# Use a different initial guess to find the other root
# (Answer x2 = -2.79128785)
x_guess=-3
x2=opt.minimize(S,x_guess).x

print(x2)

#%%
#-----------------------------------------------------------
# B. Systems of equations (n equations, n unknowns)
#-----------------------------------------------------------
#
# We can also use minimize to solve systems of nonlinear equations.
# Instead of f(x) = 0, we have:
#   f0 (x0, x1, ..., xn-1) = 0
#   f1 (x0, x1, ..., xn-1) = 0
#   ...
#   fn-1 (x0, x1, ..., xn-1) = 0
#
# We can write this more compactly as f_ (x_) = 0_, where f_, x_ 
# and 0_ are vectors.
#
# Steps to solving a system of nonlinear equations using root:
# (1) import module: import scipy.optimize as opt
# (2) Put the equation in residual form, f_(x_) = 0_
# (3) Define the python function, 
#           def <fn name> (<args>):
#               res_0 = <function 0 in residual form>
#               res_1 = <function 1 in residual form>
#               ...
#               res_n-1 = <function n-1 in residual form>
#               SSE = res_0**2 + res_1**2 + ... + res_n-1**2
#               return SSE
#     The function takes a vector argument and returns a **scalar**.
# (4) Set an initial guess for x (which is now a vector)
# (5) Call "minimize" function: 
#           x = opt.minimize(<fn name>, <guess>).x

# ----------
# Example 
# ----------
# Solve:
#   y + 2z = 0
#   sin(y)/z = 0

# Writing this in our standard notation:
#   x0 + 2*x1 = 0
#   sin(x0)/x1 = 0

def F(x):
  F0 = x[0] + 2*x[1]
  F1 = np.sin(x[0]) / x[1]
  SSE = F0**2 + F1**2
  return SSE

x_guess = np.array([1, 2])
x = opt.minimize( F, x_guess ).x
print('Example 2')
print('(y, z) = ', x)
print("residual = ", F(x))

# ----------
# Practice 
# ----------
# Solve the following system of three equations in three unknowns
# 
# x^2 + y^2 = 4
# xy + yz = -1
# y^2 + z^2 = 2.
# 
# A reasonable guess for all variables is x = 1, y = 2, z = 1.
# (Answer: x = 1.60890092, y = -1.18803949, z = -0.76717806)

def s(x):
    f0=(x[0]**2)+(x[1]**2)-4
    f1=(x[0]*x[1])+(x[1]*x[2])+1
    f2=(x[1]**2)+(x[2]**2)-2
    SSE=(f0**2)+(f1**2)+(f2**2)
    return SSE
guess=np.array([1,2,1])
x3=opt.minimize(s,guess).x
print(x3)

#%%
a=np.array([-1.60890092,1.18803949,0.76717806])
f0=(a[0]**2)+(a[1]**2)
f1=(a[0]*a[1])+(a[1]*a[2])
f2=(a[1]**2)+(a[2]**2)
print(f0)
print(f1)
print(f2)


    