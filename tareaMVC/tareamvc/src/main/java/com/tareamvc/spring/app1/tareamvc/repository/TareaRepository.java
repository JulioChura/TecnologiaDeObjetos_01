package com.tareamvc.spring.app1.tareamvc.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import com.tareamvc.spring.app1.tareamvc.model.Tarea;

@Repository
public interface TareaRepository extends JpaRepository<Tarea, Long> {

}
