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
public interface Fila <E>{
    void add(E novo);
    void imprime();
    No remove();
    boolean isEmpty();
    
}
