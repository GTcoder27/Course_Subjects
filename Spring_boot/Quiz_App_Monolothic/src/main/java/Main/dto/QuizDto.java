package Main.dto;

import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class QuizDto {
    private String uniqueCode;
    @ManyToMany
    private List<QuestionDto> questions;
}
