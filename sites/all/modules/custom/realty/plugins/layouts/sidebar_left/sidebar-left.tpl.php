<?php
/**
 * @file
 *
 * Template (admin) for the ob-glossary layout.
 */
?>
<div id="wrapper">
  <?php if (!empty($content['top'])) : ?>
        <?php print $content['top']; ?>
  <?php endif; ?>

  <div class="container fin last-block">
    <div class="container fin zero-padding">
      <div class="col-xs-9 zero-padding">
        <?php if (!empty($content['content_left'])) : ?>
          <?php print $content['content_left']; ?>
        <?php endif; ?>
      </div>
      <div class="col-xs-3">
        <?php if (!empty($content['content_right'])) : ?>
          <?php print $content['content_right']; ?>
        <?php endif; ?>
      </div>
    </div>
  </div>
