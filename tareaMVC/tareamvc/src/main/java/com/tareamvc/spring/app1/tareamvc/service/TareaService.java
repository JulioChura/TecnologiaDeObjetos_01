package com.tareamvc.spring.app1.tareamvc.service;

import com.tareamvc.spring.app1.tareamvc.model.Tarea;
import com.tareamvc.spring.app1.tareamvc.repository.TareaRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

@Service
public class TareaService {
    
    @Autowired
    private TareaRepository tareaRepository;
    
    public List<Tarea> obtenerTodasLasTareas() {
        return tareaRepository.findAll();
    }
    
    public Tarea guardarTarea(Tarea tarea) {
        return tareaRepository.save(tarea);
    }
    
    public void eliminarTarea(Long id) {
        tareaRepository.deleteById(id);
    }
    
    public Optional<Tarea> obtenerTareaPorId(Long id) {
        return tareaRepository.findById(id);
    }
    
    public Tarea toggleCompletada(Long id) {
        Optional<Tarea> tareaOpt = tareaRepository.findById(id);
        if (tareaOpt.isPresent()) {
            Tarea tarea = tareaOpt.get();
            tarea.setCompletada(!tarea.isCompletada());
            return tareaRepository.save(tarea);
        }
        return null;
    }
}