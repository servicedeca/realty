<div class="modal_checkbox">
  <span>
      <input
        id="<?php print render($element['#attributes']['id']); ?>"
        name="<?php print render($element['#name']); ?>"
        value="<?php print render($element['#default_value']); ?>"
        type="checkbox"
        <?php $element['#checked'] ? print " checked='checked'" : ''; ?>
        <?php isset($element['#disabled']) && $element['#disabled'] ? print " disabled" : ''; ?>>
  </span>
  <label class="dls-checkbox-wrapper" for="<?php print render($element['#id']); ?>">
</div>

