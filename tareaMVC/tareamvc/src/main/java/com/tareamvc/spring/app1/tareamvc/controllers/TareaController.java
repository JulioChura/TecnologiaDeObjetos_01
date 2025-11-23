package com.tareamvc.spring.app1.tareamvc.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import com.tareamvc.spring.app1.tareamvc.model.Tarea;
import com.tareamvc.spring.app1.tareamvc.service.TareaService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

@Controller
public class TareaController {
    
    @Autowired
    private TareaService tareaService;
    
    // Página principal - muestra todas las tareas
    @GetMapping("/")
    public String listarTareas(Model model) {
        model.addAttribute("tareas", tareaService.obtenerTodasLasTareas());
        model.addAttribute("nuevaTarea", new Tarea());
        return "index";
    }
    
    // Crear nueva tarea
    @PostMapping("/tareas")
    public String crearTarea(@ModelAttribute Tarea nuevaTarea) {
        tareaService.guardarTarea(nuevaTarea);
        return "redirect:/"; // Vuelve a la página principal
    }
    
    // Marcar/desmarcar como completada
    @PostMapping("/tareas/{id}/toggle")
    public String toggleCompletada(@PathVariable Long id) {
        tareaService.toggleCompletada(id);
        return "redirect:/";
    }
    
    // Eliminar tarea
    @PostMapping("/tareas/{id}/eliminar")
    public String eliminarTarea(@PathVariable Long id) {
        tareaService.eliminarTarea(id);
        return "redirect:/";
    }
}
