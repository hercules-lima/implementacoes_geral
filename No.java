/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package brincs;

/**
 *
 * @author Douglas Costa
 */
public class No <E>{
    private E dado;
    private No prox;
    
    No(){}
    No(E dado){
        this.dado = dado;
    }
    
    public void SetE(E a){
        this.dado = a;     
    }
    public E GetE(){
        return dado;
    }
    public void setProx(No prox){
        this.prox = prox;
    }
    public No getProx(){
        return this.prox;
    }
    
}
